open TexasGame;

let component = ReasonReact.statelessComponent("PokerPrompt");

let make = (~game, ~onPrompt, _children) => {
  ...component,
  render: (self) =>
    game == PreFlop ?
      <a onClick=((_event) => onPrompt(Deal: action))> (ReasonReact.stringToElement("Deal")) </a> :
      <div>
        <a onClick=((_event) => onPrompt(Check))> (ReasonReact.stringToElement("Check ")) </a>
        <a onClick=((_event) => onPrompt(Bet))> (ReasonReact.stringToElement(" Bet ")) </a>
        <a onClick=((_event) => onPrompt(Fold))> (ReasonReact.stringToElement(" Fold")) </a>
      </div>
};