open Card;

type deck = list(card);

let getRandomCard = (deck) => {
  let drawnCard = List.length(deck) |> Random.int |> List.nth(deck);
  let newDeck = List.filter((card) => card != drawnCard, deck);
  (drawnCard, newDeck)
};

let getCard = (deck) => (List.hd(deck), List.tl(deck));

let rec getCards = (cards, deck, numCards) =>
  switch numCards {
  | 0 => (cards, deck)
  | _ =>
    let (newCard, newDeck) = getCard(deck);
    let remainingCards = numCards - 1;
    getCards([newCard, ...cards], newDeck, remainingCards)
  };

let shuffle = (deck) => {
  let cardPlusRandomTuples = List.map((c) => (Random.bits(), c), deck);
  let sortedCardPlusRandomTuples = List.sort(compare, cardPlusRandomTuples);
  List.map(snd, sortedCardPlusRandomTuples)
};

let makeDeck = () =>
  List.concat(List.map((value) => List.map((suit) => (value, suit), suits), values));

let printDeck = (deck) => List.iter((card) => Js.log(printCard(card)), deck);