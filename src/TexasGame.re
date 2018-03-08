open Card;

open Deck;

open Board;

type dealer = player;

type action =
  | Deal
  | Check
  | Bet
  | Prompt
  | Fold;

type game =
  | PreFlop
  | Flop
  | Middle
  | End;

let rec dealToPlayers = (board, playersToBeDelt, numCards) =>
  /* only works with fresh players */
  switch playersToBeDelt {
  | [] => board
  | [hd, ...tl] =>
    let (deck, players) = board;
    let (deltCards, newDeck) = Deck.getCards([], deck, numCards);
    let playerWithNewCard = {...hd, hand: deltCards};
    let newPlayers = List.append(players, [playerWithNewCard]);
    let newBoard = (newDeck, newPlayers);
    dealToPlayers(newBoard, tl, numCards)
  };

let dealToDealer = (deck, dealer, numCards) => {
  /*need to generalize dealToPlayers to have method for dealer or players */
  let (deltCards, newDeck) = Deck.getCards([], deck, numCards);
  let dealerWithNewCard = {...dealer, hand: deltCards};
  (newDeck, dealerWithNewCard)
};

let dealFlop = (deck, players) => {
  let board = (deck, []);
  dealToPlayers(board, players, 2)
};

let deal = (players) => {
  let deck = Deck.makeDeck();
  let shuffledDeck = Deck.shuffle(deck);
  dealFlop(shuffledDeck, players)
};

let printPlayers = (players) =>
  List.map(
    (player) => {
      Js.log("****** Player " ++ string_of_int(player.id) ++ " *******");
      List.map((card) => Js.log(Card.printCard(card)), player.hand)
    },
    players
  );