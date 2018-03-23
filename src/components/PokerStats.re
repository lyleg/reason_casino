let component = ReasonReact.statelessComponent("PokerStats");

let make = (~round, ~players, ~pool, _children) => {
  ...component,
  render: (self) =>
    <div>
      <h2> (ReasonReact.stringToElement("Statz")) </h2>
      <div>
        <h3> (ReasonReact.stringToElement("Pool: ")) </h3>
        <div> (ReasonReact.stringToElement(string_of_int(pool))) </div>
      </div>
      <div>
        <h3> (ReasonReact.stringToElement("Round: ")) </h3>
        <div> (ReasonReact.stringToElement(round)) </div>
      </div>
    </div>
};