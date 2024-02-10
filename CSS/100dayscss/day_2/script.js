$(document).ready(function() {
    $('.frame').on('click', '.icon', function() {
        $(this).toggleClass('active');
        $(this).find('div').removeClass('no-animation');
    });
});
