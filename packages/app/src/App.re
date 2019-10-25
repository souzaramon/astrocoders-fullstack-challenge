module TweetsQueryConfig = [%graphql
  {|
  query {
    tweets {
      id
      text
      user {
        screen_name
      }
      created_at
    }
  }
|}
];

module TweetsQuery = ReasonApolloHooks.Query.Make(TweetsQueryConfig);

[@react.component]
let make = () => {
  let (_simple, full) = TweetsQuery.use();
  let url = ReasonReactRouter.useUrl();
  let theme = Themes.sky;

  switch (full) {
  | {loading: true, data: None} => <ACLoading />
  | {data: Some(data)} =>
    <LayoutBase theme>
      {switch (url.path) {
       | ["mail", id] => <PageEmail theme data id />
       | _ => <PageInbox theme data />
       }}
    </LayoutBase>
  | _ =>
    <span>
      {React.string("Are the backend server running? Please check the: ")}
      <a href="http://localhost:8001" target="_blank">
        {React.string("http://localhost:8001")}
      </a>
    </span>
  };
};
