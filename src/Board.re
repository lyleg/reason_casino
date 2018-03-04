open Card;

type hand = list(card);

type player = {
  id: int,
  hand,
  name: string
};

type players = list(player);

type table = {activePlayer: int};