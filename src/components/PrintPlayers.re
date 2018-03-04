open Board;

let component = ReasonReact.statelessComponent("PrintPlayers");

let make = (~players, _children) => {
  ...component, /* spread the template's other defaults into here  */
  render: (self) =>
    <div style=(ReactDOMRe.Style.make(~color="#444444", ~fontSize="22px", ()))>
      <h1> (ReasonReact.stringToElement("Players")) </h1>
      (
        ReasonReact.arrayToElement(
          Array.of_list(
            List.mapi(
              (idx, player) => {
                List.map((card) => Js.log(Card.printCard(card)), player.hand);
                <div
                  key=(string_of_int(idx)) style=(ReactDOMRe.Style.make(~marginBottom="20px", ()))>
                  (ReasonReact.stringToElement(player.name))
                  (ReasonReact.stringToElement(" (" ++ string_of_int(player.id) ++ ")"))
                  <Hand hand=player.hand />
                </div>
              },
              players
            )
          )
        )
      )
    </div>
};