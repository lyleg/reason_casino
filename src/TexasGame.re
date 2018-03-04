open Card;

open Deck;

open Board;

type prompt = bool;

type action =
  | Deal
  | Prompt;

type game =
  | PreFlop
  | Flop
  | Middle
  | End;

let rec dealToPlayers = (board, playersToBeDelt, numCards) =>
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