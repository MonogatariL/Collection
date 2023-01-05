document.addEventListener('DOMContentLoaded', ready)
function ready () {
  effects()
}

function effects () {
  const inner = document.querySelector('.header__inner')
  const mobile = document.querySelector('.mobile-img')
  inner.style.transform = 'translate(0, 0)'
  inner.style.opacity = 1

  mobile.style.opacity = 1
  mobile.style.transform = 'translate(0,0)'
}

document.onscroll = function () {
  const goTop = document.querySelector('.go-top')
  if (document.documentElement.scrollTop > 1000) {
    goTop.style.visibility = 'visible'
    goTop.style.opacity = '1'
    goTop.style.transform = 'translate(50%, 0)'
  }

  if (document.documentElement.scrollTop < 200) {
    goTop.style.transform = 'translate(50%, 300%)'
  }
}