open TexasGame;

open Deck;

open Board;

open Player;

type state = {
  deck,
  players,
  round,
  dealer,
  pool
};

type action =
  | Deal
  | Prompt(promptResponse);

let component = ReasonReact.reducerComponent("Texas");

let make = (_children) => {
  ...component,
  initialState: () => {
    deck: [],
    pool: 0,
    round: PreFlop,
    players: [
      {id: 1, hand: [], name: "John", money: 1000, src: Computer},
      {id: 2, hand: [], name: "Lyle", money: 1000, src: Human}
    ],
    dealer: {id: 1, hand: [], name: "Dealer", money: 0, src: Computer}
  },
  reducer: (action, state) =>
    switch action {
    | Deal =>
      let (deck, deltPlayers) = deal(state.players);
      ReasonReact.Update({...state, round: Flop, players: deltPlayers, deck})
    | Prompt(promptResponse) =>
      let player1Prompt = randomBot(1);
      let player2Prompt = {id: 2, promptResponse};
      let prompts = [player1Prompt, player2Prompt];
      let (players, dealer) = processPlayers([], state.players, state.dealer, prompts);
      let board = (state.deck, players);
      let (deck, deltPlayers, round) =
        switch state.round {
        | Flop =>
          let (deck, deltPlayers) = dealToPlayers(board, players, 1);
          (deck, deltPlayers, Middle)
        | Middle =>
          let (deck, deltPlayers) = dealToPlayers(board, players, 1);
          (deck, deltPlayers, River)
        | River =>
          let (deck, deltPlayers) = dealToPlayers(board, players, 1);
          (deck, deltPlayers, End)
        };
      ReasonReact.Update({...state, round, players: deltPlayers, dealer, deck})
    },
  render: (self) => {
    let round = stringFromRound(self.state.round);
    <div>
      <PrintPlayers players=self.state.players dealer=self.state.dealer />
      <PokerPrompt
        round=self.state.round
        onDeal=(() => self.send(Deal))
        onPrompt=((promptResponse: promptResponse) => self.send(Prompt(promptResponse)))
      />
      <PokerStats round players=self.state.players pool=self.state.pool />
    </div>
  }
};