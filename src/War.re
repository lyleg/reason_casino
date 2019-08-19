open Board;

open Card;

type dealer = player;

/* move dealer functions to general deal module?*/
let rec dealToPlayers = (board, playersToBeDelt: players, numCards) =>
  switch (playersToBeDelt) {
  | [] => board
  | [hd, ...tl] =>
    let (deck, players) = board;
    let (deltCards, newDeck) = Deck.getCards([], deck, numCards);
    let currentPlayer =
      players |> List.filter((player: player) => hd.id == player.id);
    let (currentPlayer, filteredPlayers) =
      players |> List.partition((player: player) => hd.id == player.id);
    let playerWithNewCard =
      switch (currentPlayer) {
      | [] => {...hd, hand: deltCards}
      | [player] => {...player, hand: List.append(player.hand, deltCards)}
      };
    let newPlayers = List.append(filteredPlayers, [playerWithNewCard]);
    let newBoard = (newDeck, newPlayers);
    dealToPlayers(newBoard, tl, numCards);
  };

let dealToDealer = (deck, dealer, numCards) => {
  /*need to generalize dealToPlayers to have method for dealer or players */
  let (deltCards, newDeck) = Deck.getCards([], deck, numCards);
  let dealerWithNewCard = {
    ...dealer,
    hand: List.append(dealer.hand, deltCards),
  };
  (newDeck, dealerWithNewCard);
};

let deal = (players, numCards) => {
  let deck = Deck.makeDeck();
  let shuffledDeck = Deck.shuffle(deck);
  let board = (shuffledDeck, []);
  dealToPlayers(board, players, numCards);
};

let compareCards = (players, dealer) => {
  compareCard(...)
};

let printPlayers = players =>
  List.map(
    (player: player) => {
      Js.log("****** Player " ++ string_of_int(player.id) ++ " *******");
      List.map(card => Js.log(Card.printCard(card)), player.hand);
    },
    players,
  );