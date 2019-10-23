const tweets = [
  {
    text: 'Harry Potter and the Chamber of Secrets',
    author: 'J.K. Rowling',
  },
  {
    text: 'Jurassic Park',
    author: 'Michael Crichton',
  },
];

export default {
  Query: {
    tweets: () => tweets,
  },
}