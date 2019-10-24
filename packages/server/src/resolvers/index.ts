import data from './mock'

export default {
  Query: {
    tweets: () => data,
    tweet: (parent, params) => data.find(d => d.id === params.id)
  },
}
