import { gql } from 'apollo-server';

export default gql`
   type Entities {
    hashtags: [Hashtag]!
  }

  type Hashtag {
    text: String!
  }

  type User {
    name: String!,
    screen_name: String!
  }

  type Tweet {
    id: String!
    text: String!
    user: User!
    created_at: String!
    entities: Entities!
  }

  type Query {
    tweets: [Tweet!]!
    tweet(id: String): Tweet!
  }
`
