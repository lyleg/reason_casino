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

type state = {
  deck,
  players,
  game
};

let component = ReasonReact.reducerComponent("Texas");

let make = (_children) => {
  ...component,
  initialState: () => {
    deck: [],
    game: PreFlop,
    players: [{id: 1, hand: [], name: "John"}, {id: 2, hand: [], name: "Lyle"}]
  },
  reducer: (action, state) =>
    switch action {
    | Deal =>
      let (deck, players) = deal(state.players);
      let game = Middle;
      ReasonReact.Update({...state, deck, players, game})
    | Prompt =>
      let game = Middle;
      ReasonReact.Update({...state, game})
    },
  render: (self) =>
    <div>
      <div>
        <PrintPlayers players=self.state.players />
        <PokerPrompt game=self.state.game onPrompt=((action: action) => self.send(action)) />
        <PokerStats game=self.state.game players=self.state.players />
      </div>
    </div>
};