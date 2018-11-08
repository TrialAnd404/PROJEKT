define(['jquery'], function($) {
    return {
        onCreate: function(content) {
            $.getJSON('userverwaltung.json', function(result) {
                $('#month').html(result.month);
                $('#days').html(result.days);
                $('#sum').html(result.sum);
            });

        },
    }
});
