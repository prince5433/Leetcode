SELECT
    id,
    IF(
        p_id IS NULL,
        'Root',
        IF(
            id IN (SELECT p_id FROM Tree WHERE p_id IS NOT NULL),
            'Inner',
            'Leaf'
        )
    ) AS type
FROM Tree;

-- p_id NULL hai, toh parent nahi hai: Root.
-- Otherwise, agar id kisi aur node ka p_id hai, toh uske children hain: Inner.
-- Agar dono conditions false hain, toh node ke children nahi hain: Leaf.
-- WHERE ki jagah classification ko SELECT ke andar IF() se banaya hai.

-- TC: O(N^2) worst case — correlated nahi, but IN subquery evaluation/optimization par depend karta hai.
-- SC: O(N) worst case — subquery ke p_id values store ho sakte hain.