import { ApolloServer } from 'apollo-server'

import typeDefs from './typedefs'
import resolvers from './resolvers'

const instance = new ApolloServer({ typeDefs, resolvers, playground: true });

export default instance