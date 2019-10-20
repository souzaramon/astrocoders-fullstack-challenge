[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  switch (url.path) {
  | ["email", id] => <PageEmail emailId=id />
  | _ => <PageInbox />
  };
};