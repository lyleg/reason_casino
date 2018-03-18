open Card;

type hand = list(card);

type playerType =
  | Human
  | Computer;

type player = {
  id: int,
  hand,
  money: int,
  name: string,
  src: playerType
};

type players = list(player);

type table = {activePlayer: int};

type pool = int;