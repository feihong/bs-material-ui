[@bs.obj]
external makeProps :
  (~className: string=?, ~component: 'union_r8wy=?, unit) => _ =
  "";

[@bs.module "@material-ui/core/TableBody/TableBody"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
           ],
         )=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~component=?
          component |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        (),
      ),
    children,
  );
