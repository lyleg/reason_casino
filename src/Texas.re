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
  prompt,
  players,
  game
};

let component = ReasonReact.reducerComponent("Texas");

let deal = (players) => {
  let deck = Deck.makeDeck();
  let shuffledDeck = Deck.shuffle(deck);
  dealFlop(shuffledDeck, players)
};

let make = (_children) => {
  ...component,
  initialState: () => {
    deck: [],
    game: PreFlop,
    prompt: false,
    players: [{id: 1, hand: []}, {id: 2, hand: []}, {id: 3, hand: []}]
  },
  reducer: (action, state) =>
    switch action {
    | Deal =>
      let (deck, players) = deal(state.players);
      let prompt = true;
      ReasonReact.Update({...state, deck, players, prompt})
    | Prompt =>
      Js.log("promptToggle");
      let prompt = false;
      ReasonReact.Update({...state, prompt})
    },
  render: (self) =>
    <div>
      <div>
        <PrintPlayers players=self.state.players />
        <PokerPrompt prompt=self.state.prompt onPrompt=((action: action) => self.send(action)) />
        <PokerStats game=self.state.game players=self.state.players />
      </div>
    </div>
};