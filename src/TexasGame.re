open Card;

open Deck;

open Board;

type dealer = player;

type prompt =
  | Check
  | Fold
  | Bet;

type playerPrompt = {
  id: int,
  prompt
};

type prompts = list(playerPrompt);

type action =
  | Deal
  | Flop(prompt)
  | Middle(prompt)
  | River(prompt);

type round =
  | PreFlop
  | Flop
  | Middle
  | End;

let rec dealToPlayers = (board, playersToBeDelt: players, numCards) =>
  switch playersToBeDelt {
  | [] => board
  | [hd, ...tl] =>
    let (deck, players) = board;
    let (deltCards, newDeck) = Deck.getCards([], deck, numCards);
    /* if player already has card ,merge, else new player */
    let currentPlayer = List.filter((player: player) => hd.id == player.id, players);
    let newPlayers =
      switch currentPlayer {
      | [] =>
        let playerWithNewCard = {...hd, hand: deltCards};
        List.append(players, [playerWithNewCard])
      | [player] =>
        let playerWithNewCard = {...player, hand: List.append(player.hand, deltCards)};
        let playersWithoutCurrentPlayer =
          /* Not crazy about the filtering stuff */
          List.filter((player: player) => hd.id != player.id, players);
        List.append(playersWithoutCurrentPlayer, [playerWithNewCard])
      };
    let newBoard = (newDeck, newPlayers);
    dealToPlayers(newBoard, tl, numCards)
  };

let dealToDealer = (deck, dealer, numCards) => {
  /*need to generalize dealToPlayers to have method for dealer or players */
  let (deltCards, newDeck) = Deck.getCards([], deck, numCards);
  let dealerWithNewCard = {...dealer, hand: deltCards};
  (newDeck, dealerWithNewCard)
};

let deal = (players) => {
  let deck = Deck.makeDeck();
  let shuffledDeck = Deck.shuffle(deck);
  let board = (shuffledDeck, []);
  dealToPlayers(board, players, 2)
};

let printPlayers = (players) =>
  List.map(
    (player: player) => {
      Js.log("****** Player " ++ string_of_int(player.id) ++ " *******");
      List.map((card) => Js.log(Card.printCard(card)), player.hand)
    },
    players
  );