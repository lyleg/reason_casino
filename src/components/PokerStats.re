let component = ReasonReact.statelessComponent("PokerStats");

let make = (~game, ~players, _children) => {
  ...component,
  render: (self) => <div> (ReasonReact.stringToElement("Statz")) </div>
};