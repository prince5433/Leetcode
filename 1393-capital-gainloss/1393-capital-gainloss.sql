SELECT
    stock_name,
    SUM(
        IF(operation = 'Buy', -price, price)
    ) AS capital_gain_loss
FROM Stocks
GROUP BY stock_name;

-- Buy ko negative rakha hai kyunki woh paisa kharch karta hai.
-- Sell positive hai kyunki woh paisa receive karta hai.
-- SUM() har stock ke saare Buy/Sell amounts ka net total nikalta hai.
-- GROUP BY stock_name har stock ka result alag banata hai.

-- TC: O(N) — table ki rows aggregate karni padti hain.
-- SC: O(K) — K distinct stocks ke aggregation results store hote hain.