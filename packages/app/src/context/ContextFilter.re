open Types;

type dispatch = filterAction => unit;
type contextValue = (filter, dispatch);

let initValue: contextValue = ("", _ => ignore());

let context = React.createContext(initValue);

let make = React.Context.provider(context);

let makeProps = (~value, ~children, ()) => {
  "value": value,
  "children": children,
};
