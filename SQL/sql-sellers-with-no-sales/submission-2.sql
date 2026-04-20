select s.seller_name
from seller s
left join orders o
    on s.seller_id = o.seller_id
    and date_part('year', o.sale_date) = 2020
where o.order_cost is null
order by s.seller_name asc;
