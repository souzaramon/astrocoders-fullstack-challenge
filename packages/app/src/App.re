[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let theme = Themes.sky;

  <ReasonApolloHooks.ApolloProvider client=GraphQLClient.client>
    <LayoutBase theme>
      {switch (url.path) {
       | ["mail", id] => <PageEmail theme id />
       | _ => <PageInbox theme />
       }}
    </LayoutBase>
  </ReasonApolloHooks.ApolloProvider>;
};
