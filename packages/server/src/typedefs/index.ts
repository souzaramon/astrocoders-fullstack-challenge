import { gql } from 'apollo-server';

export default gql`
  type Tweet {
    text: String
    author: String
  }

  type Query {
    tweets: [Tweet]
  }
`