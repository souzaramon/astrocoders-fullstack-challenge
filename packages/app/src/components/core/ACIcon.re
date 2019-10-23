[@react.component]
let make = (~name, ~className="") =>
  <i className={"material-icons " ++ className}> {React.string(name)} </i>;