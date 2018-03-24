let component = ReasonReact.statelessComponent("ViewCard");

let make = (~card, _children) => {
  ...component, /* spread the template's other defaults into here  */
  render: (_self) => {
    let cardText = Card.printCard(card);
    <div> (ReasonReact.stringToElement(cardText)) </div>
  }
};