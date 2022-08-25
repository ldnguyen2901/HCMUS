<?php
    $shop = array ( array ("title"=>"rose", "price"=>1.25, "number"=>15),
                  array ("title"=>"daisy", "price"=>0.75 , "number"=>25),
                  array ("title"=>"orchid", "price"=>1.15 , "number"=>7)
                 );
?>
<?php if (count ($shop) > 0): ?>
   <style type = "text/css">
        table, th, td {border: 1px solid black;
            border-collapse: collapse;};
    </style>
   <table>
      <thead>
       <tr>
          <th><?php echo implode ('</th><th>', array_keys (current ($shop))); ?></th>
       </tr>
     </thead>
      <tbody>
        <?php foreach ($shop as $row) : array_map ('htmlentities', $row); ?>
            <tr>
              <td><?php echo implode ('</td><td>', $row); ?></td>
            </tr>
        <?php endforeach; ?>
      </tbody>
    </table>
<?php endif; ?>