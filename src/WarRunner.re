open War;

open Card;

open Board;

let players = [
  {id: 1, hand: [], name: "John", money: 1000, src: Computer},
  {id: 2, hand: [], name: "Lyle", money: 1000, src: Human},
];

let dealer = {id: 0, hand: [], name: "Dealer", money: 0, src: Computer};

let (deck, deltPlayers) = deal(players, 1);

let (finalDeck, deltDealer) = dealToDealer(deck, dealer, 1);

compareCards(deltPlayers, deltDealer);