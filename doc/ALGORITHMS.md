# Algorithms

XMRig uses a different way to specify algorithms, compared to other miners.

Algorithm selection splitted to 2 parts:

 * Global base algorithm per miner or proxy instance, `algo` option. Possible values: `cryptonight`, `cryptonight-lite`, `cryptonight-heavy`.
 * Algorithm variant specified separately for each pool, `variant` option.
 * [Full table for supported algorithm and variants.]
 
#### Example
```json
{
  "algo": "cryptonight",
  ...
  "pools": [
    {
      "url": "...",
      "variant": 1,
      ...
    }
 ],
 ...
}
```

## Mining algorithm negotiation
If your pool support [mining algorithm negotiation] miner will choice proper variant automaticaly and if you choice wrong base algorithm you will see error message.


