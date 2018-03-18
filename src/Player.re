open TexasGame;

open Board;

let processComputerPlayerPrompt = (players, game) => {
  let rand = Random.int(2);
  switch rand {
  | 0 => Check
  | 1 => Fold
  | 2 => Bet
  | _ => Check
  }
};

let processPlayer = (player: player, dealer: player, prompts: prompts) => {
  let playerPrompt = prompts |> List.find((x: playerPrompt) => x.id == player.id);
  let wager =
    switch playerPrompt.prompt {
    | Bet => 100
    | _ => 0
    };
  let newDealer = {...dealer, money: dealer.money + wager};
  let newPlayer = {...player, money: player.money - wager};
  (newPlayer, newDealer)
};

/* hardoding for 1 player, will only be 1 human prompt for each round */
let rec processPlayers =
        (processedPlayers: players, players: players, dealer: player, prompts: prompts) =>
  switch players {
  | [] => (processedPlayers, dealer)
  | [hd, ...tl] =>
    let (player, newDealer) = processPlayer(hd, dealer, prompts);
    processPlayers(List.append(processedPlayers, [player]), tl, newDealer, prompts)
  };