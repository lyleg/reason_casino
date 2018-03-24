open Board;

type dealer = player;

type promptResponse =
  | Check
  | Fold
  | Bet;

type playerPrompt = {
  id: int,
  promptResponse
};

type prompts = list(playerPrompt);

type round =
  | PreFlop
  | Flop
  | Middle
  | River
  | End;

let stringFromRound = (round) =>
  switch round {
  | PreFlop => "PreFlop"
  | Flop => "Flop"
  | Middle => "Middle"
  | River => "River"
  | End => "End"
  };

let rec dealToPlayers = (board, playersToBeDelt: players, numCards) =>
  switch playersToBeDelt {
  | [] => board
  | [hd, ...tl] =>
    let (deck, players) = board;
    let (deltCards, newDeck) = Deck.getCards([], deck, numCards);
    let currentPlayer = players |> List.filter((player: player) => hd.id == player.id);
    let (currentPlayer, filteredPlayers) =
      players |> List.partition((player: player) => hd.id == player.id);
    let playerWithNewCard =
      switch currentPlayer {
      | [] => {...hd, hand: deltCards}
      | [player] => {...player, hand: List.append(player.hand, deltCards)}
      };
    let newPlayers = List.append(filteredPlayers, [playerWithNewCard]);
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