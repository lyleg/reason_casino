/*
 Firstly, you are dealt your hole cards. Then there is a round of betting.
 Then the players remaining see a flop. Then there is another round of betting.
 Then you see a turn card. Then another round of betting. Then a final river card.
 Then one more round of betting.
 The best five card hand wins.
 */
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
    | Flop(prompt) =>
      let round = Middle;
      let player1Prompt = {id: 1, prompt};
      let player2Prompt = {id: 2, prompt};
      let prompts = [player1Prompt, player2Prompt];
      let (players, dealer) = processPlayers([], state.players, state.dealer, prompts);
      ReasonReact.Update({...state, round, players, dealer})
    | Middle(prompt) =>
      let round = Middle;
      ReasonReact.Update({...state, round})
    | River(prompt) =>
      let round = Middle;
      ReasonReact.Update({...state, round})
    | Deal =>
      let (deck, players) = deal(state.players);
      let round = Flop;
      ReasonReact.Update({...state, deck, players, round})
    },
  render: (self) =>
    <div>
      <PrintPlayers players=self.state.players dealer=self.state.dealer />
      <PokerPrompt round=self.state.round onPrompt=((action: action) => self.send(action)) />
      <PokerStats round=self.state.round players=self.state.players pool=self.state.pool />
    </div>
};