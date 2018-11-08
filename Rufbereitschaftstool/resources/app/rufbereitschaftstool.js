define(['jquery'], function($) {

    return {
        onCreate: function(content) {
            $('#rufbereitschaftstool_content').load("rufbereitschaftstable.html"); 
/*            $.getJSON('rufbereitschaft.json', function(result) {
                //dummyData = ["Dummy"];
                var monthData = result.monthData;
                
                for (var i=0; i<monthData.length; i++)
                {
                    dummyData.push(result.monthData[i]);
                };
                var dataSet = [dummyData];
                
                var dataSet = {name:"dummy", data:monthData};
                var table = $('#example').DataTable({
                    data:
                        dataSet,
                    columns: [
                        {title: "test"},
                        {title: "1"},
                        {title: "2"},
                        {title: "3"},
                        {title: "4"},
                        {title: "5"},
                        {title: "6"},
                        {title: "7"},
                        {title: "8"},
                        {title: "9"},
                        {title: "10"},
                        {title: "11"},
                        {title: "12"},
                        {title: "13"},
                        {title: "14"},
                        {title: "15"},
                        {title: "16"},
                        {title: "17"},
                        {title: "18"},
                        {title: "19"},
                        {title: "20"},
                        {title: "21"},
                        {title: "22"},
                        {title: "23"},
                        {title: "24"},
                        {title: "25"},
                        {title: "26"},
                        {title: "27"},
                        {title: "28"},
                        {title: "29"},
                        {title: "30"},
                        {title: "31"}
                    ]                      
                });
            });*/
        },
    }
});
