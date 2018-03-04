open Board;

let component = ReasonReact.statelessComponent("Hand");

let make = (~hand, _children) => {
  ...component, /* spread the template's other defaults into here  */
  render: (self) =>
    <div>
      (
        ReasonReact.arrayToElement(
          Array.of_list(
            List.mapi(
              (idx, card) => <span key=(string_of_int(idx))> <ViewCard card /> </span>,
              hand
            )
          )
        )
      )
    </div>
};