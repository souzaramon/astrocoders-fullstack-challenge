let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

let appId = "e8666ff5-b508-4b11-bcc6-b3db31403340";

let authConfig =
  OneGraphAuth.createOptions(
    ~appId,
    ~oneGraphOrigin="https://serve.onegraph.com/",
    (),
  );

let auth = OneGraphAuth.create(authConfig);

let httpLink =
  ApolloLinks.createHttpLink(
    ~uri="https://serve.onegraph.com/dynamic?app_id=" ++ appId,
    (),
  );

let headerContextLink =
  ApolloLinks.createContextLink(() =>
    {
      "headers": {
        "authorization":
          switch (Js.Nullable.toOption(OneGraphAuth.accessToken(auth))) {
          | None => ""
          | Some(token) => "Bearer " ++ token##accessToken
          },
      },
    }
  );

let client =
  ReasonApollo.createApolloClient(
    ~link=ApolloLinks.from([|headerContextLink, httpLink|]),
    ~cache=inMemoryCache,
    (),
  );