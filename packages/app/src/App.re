open Types;

let theme = {
  dark: true,
  background: Css.backgroundImage(Css.url("/assets/bg.jpg")),
};

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  <ReasonApolloHooks.ApolloProvider client=GraphQLClient.client>
    {switch (url.path) {
     | _ => <PageInbox theme />
     }}
  </ReasonApolloHooks.ApolloProvider>;
};