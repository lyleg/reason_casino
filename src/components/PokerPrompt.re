open TexasGame;

let component = ReasonReact.statelessComponent("PokerPrompt");

let make = (~round, ~onPrompt, _children) => {
  ...component,
  render: (self) =>
    round == PreFlop ?
      <a onClick=((_event) => onPrompt(Deal: action))> (ReasonReact.stringToElement("Deal")) </a> :
      <div>
        <a onClick=((_event) => onPrompt(Flop(Check)))>
          (ReasonReact.stringToElement("Check "))
        </a>
        <a onClick=((_event) => onPrompt(Flop(Bet)))> (ReasonReact.stringToElement(" Bet ")) </a>
        <a onClick=((_event) => onPrompt(Flop(Fold)))> (ReasonReact.stringToElement(" Fold")) </a>
      </div>
};