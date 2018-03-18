open TexasGame;

open Board;

let randomBot = (id) => {
  let rand = Random.int(3);
  let prompt =
    switch rand {
    | 0 => Check
    | 1 => Fold
    | 2 => Bet
    | _ => Check
    };
  {id, prompt}
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

let rec processPlayers =
        (processedPlayers: players, players: players, dealer: player, prompts: prompts) =>
  switch players {
  | [] => (processedPlayers, dealer)
  | [hd, ...tl] =>
    let (player, newDealer) = processPlayer(hd, dealer, prompts);
    processPlayers(List.append(processedPlayers, [player]), tl, newDealer, prompts)
  };