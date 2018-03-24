open TexasGame;

open Texas;

let component = ReasonReact.statelessComponent("PokerPrompt");

let make = (~round, ~onPrompt, _children) => {
  ...component,
  render: (self) =>
    round == PreFlop ?
      <a onClick=((_event) => onPrompt(Prompt(Deal)))> (ReasonReact.stringToElement("Deal")) </a> :
      <div>
        <a onClick=((_event) => onPrompt(Prompt(Check)))>
          (ReasonReact.stringToElement("Check "))
        </a>
        <a onClick=((_event) => onPrompt(Prompt(Bet)))> (ReasonReact.stringToElement(" Bet ")) </a>
        <a onClick=((_event) => onPrompt(Prompt(Fold)))>
          (ReasonReact.stringToElement(" Fold"))
        </a>
      </div>
};