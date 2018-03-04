open TexasGame;

let component = ReasonReact.statelessComponent("PokerPrompt");

let make = (~prompt, ~onPrompt, _children) => {
  ...component,
  render: (self) =>
    prompt ?
      <a onClick=((_event) => onPrompt(Prompt: action))>
        (ReasonReact.stringToElement("Prompt"))
      </a> :
      <a onClick=((_event) => onPrompt(Deal: action))> (ReasonReact.stringToElement("Deal")) </a>
};