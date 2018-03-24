open TexasGame;

let component = ReasonReact.statelessComponent("PokerPrompt");

let make = (~round, ~onPrompt, ~onDeal, _children) => {
  ...component,
  render: (self) =>
    round == PreFlop ?
      <a onClick=((_event) => onDeal())> (ReasonReact.stringToElement("Deal")) </a> :
      <div>
        <a onClick=((_event) => onPrompt(Check))> (ReasonReact.stringToElement("Check ")) </a>
        <a onClick=((_event) => onPrompt(Bet))> (ReasonReact.stringToElement(" Bet ")) </a>
        <a onClick=((_event) => onPrompt(Fold))> (ReasonReact.stringToElement(" Fold")) </a>
      </div>
};