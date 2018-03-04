open Card;

let shuffleAndDeal = (deck) => {
  let shuffledDeck = Deck.shuffle(deck);
  let (player1Card, deck1) = Deck.getCard(shuffledDeck);
  let (player2Card, deck2) = Deck.getCard(deck1);
  (player1Card, player2Card, deck2)
};

let printResult = (player1Card, player2Card, comparison) => {
  let (player1Value, player1Suit) = player1Card;
  let (player2Value, player2Suit) = player2Card;
  Js.log(
    "Player 1 => " ++ Card.strFromValue(player1Value) ++ " " ++ Card.strFromSuit(player1Suit)
  );
  Js.log(
    "Player 2 => " ++ Card.strFromValue(player2Value) ++ " " ++ Card.strFromSuit(player2Suit)
  );
  switch comparison {
  | Higher => Js.log("Player 1 wins")
  | Lower => Js.log("Player 2 wins")
  | Tie => Js.log("Tie")
  }
};

let rec play = (deck) => {
  let (player1Card, player2Card, dealtDeck) = shuffleAndDeal(deck);
  let comparison = compareCard(player1Card, player2Card);
  printResult(player1Card, player2Card, comparison);
  switch comparison {
  | Tie => play(dealtDeck)
  | _ => ()
  }
};

let deck = Deck.makeDeck();

play(deck);