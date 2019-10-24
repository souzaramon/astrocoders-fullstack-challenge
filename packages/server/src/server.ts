import { ApolloServer, gql } from 'apollo-server'
import { getTweetsByHashtag } from './services/twit'

const instance = new ApolloServer({
  typeDefs: gql`
    type Entities {
      hashtags: [Hashtag]!
    }

    type Hashtag {
      text: String!
    }

    type User {
      name: String!,
      screen_name: String!
      profile_image_url_https: String!
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
    }
`,

  resolvers: {
    Query: {
      tweets: async () => await getTweetsByHashtag("mars"),
    },
  },

  playground: true
});

export default instance
