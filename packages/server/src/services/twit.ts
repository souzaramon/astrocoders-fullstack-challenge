import { config } from "dotenv"
import * as Twit from 'twit';

config();

const T = new Twit({
  consumer_key: process.env.CONSUMER_KEY,
  consumer_secret: process.env.CONSUMER_SECRET,
  access_token: process.env.ACCESS_TOKEN,
  access_token_secret: process.env.ACCESS_TOKEN_SECRET,
  timeout_ms: 60 * 1000,
  strictSSL: true,
})

export function getTweetsByHashtag(hashtag: string) {
  return new Promise((resolve, reject) => T.get('search/tweets', { q: `%23${hashtag}`, count: 40 }, (err, data) => {
    if (err) {
      return reject(err);
    }

    return resolve(data.statuses);
  }))
}
