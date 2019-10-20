[@react.component]
let make = (~emailId) =>
  <LayoutBase> <div> {React.string(emailId)} </div> </LayoutBase>;