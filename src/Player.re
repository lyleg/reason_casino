open TexasGame;

let computePrompt = (players, game) => {
  let rand = Random.int(2);
  switch rand {
  | 0 => Check
  | 1 => Fold
  | 2 => Bet
  }
};