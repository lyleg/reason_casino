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
    dealer: {id: 0, hand: [], name: "Dealer", money: 0, src: Computer}
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
      let deck = state.deck;
      let (deck, deltDealer, round) =
        switch state.round {
        | PreFlop =>
          let (deck, deltDealer) = dealToDealer(deck, dealer, 0);
          (deck, deltDealer, Flop)
        | Flop =>
          let (deck, deltDealer) = dealToDealer(deck, dealer, 3);
          (deck, deltDealer, Middle)
        | Middle =>
          let (deck, deltDealer) = dealToDealer(deck, dealer, 1);
          (deck, deltDealer, River)
        | River =>
          let (deck, deltDealer) = dealToDealer(deck, dealer, 1);
          (deck, deltDealer, End)
        | End =>
          let (deck, deltDealer) = dealToDealer(deck, dealer, 0);
          (deck, deltDealer, End)
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