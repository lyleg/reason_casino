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
      {id: 2, hand: [], name: "John", money: 1000, src: Computer},
      {id: 3, hand: [], name: "Lyle", money: 1000, src: Human}
    ],
    dealer: {id: 1, hand: [], name: "Dealer", money: 0, src: Computer}
  },
  reducer: (action, state) =>
    switch action {
    | Deal =>
      let (deck, deltPlayers) = deal(state.players);
      ReasonReact.Update({...state, round: Flop, players: deltPlayers, deck})
    | Prompt(promptResponse) =>
      let player1Prompt = randomBot(2);
      let player2Prompt = {id: 3, promptResponse};
      let prompts = [player1Prompt, player2Prompt];
      let (players, dealer) = processPlayers([], state.players, state.dealer, prompts);
      let board = (state.deck, players);
      let (deck, deltDealer, round) =
        switch state.round {
        | PreFlop =>
          let (deck, deltDealer) = dealToPlayers(board, [dealer], 0);
          (deck, deltDealer |> List.hd, Flop)
        | Flop =>
          let (deck, deltDealer) = dealToPlayers(board, [dealer], 3);
          (deck, deltDealer |> List.hd, Middle)
        | Middle =>
          let (deck, deltDealer) = dealToPlayers(board, [dealer], 1);
          (deck, deltDealer |> List.hd, River)
        | River =>
          let (deck, deltDealer) = dealToPlayers(board, [dealer], 1);
          (deck, deltDealer |> List.hd, End)
        | End =>
          let (deck, deltDealer) = dealToPlayers(board, [dealer], 0);
          (deck, deltDealer |> List.hd, End)
        };
      ReasonReact.Update({...state, round, players, dealer: deltDealer, deck})
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