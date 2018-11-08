requirejs.config({
    baseUrl: 'js',
    paths: {
        jquery: 'jquery-3.3.1.min',
        Noty: 'noty.min',
        app: '../app',
        'datatables.net': 'datatables'
    }
});

requirejs(['app/main']);
