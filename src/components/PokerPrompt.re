open TexasGame;

let component = ReasonReact.statelessComponent("PokerPrompt");

let make = (~game, ~onPrompt, _children) => {
  ...component,
  render: (self) =>
    game == PreFlop ?
      <a onClick=((_event) => onPrompt(Deal: action))> (ReasonReact.stringToElement("Deal")) </a> :
      <a onClick=((_event) => onPrompt(Prompt: action))>
        (ReasonReact.stringToElement("Prompt"))
      </a>
};