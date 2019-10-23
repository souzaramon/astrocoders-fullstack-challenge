open Types;

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let theme = {
    dark: true,
    background: Css.backgroundImage(Css.url("/assets/bg.jpg")),
  };

  switch (url.path) {
  | _ => <PageInbox theme />
  };
};