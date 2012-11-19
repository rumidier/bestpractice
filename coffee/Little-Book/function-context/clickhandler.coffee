this.clickHandler = -> alert "clicked"
element.addEventListener "click", (e) => this.clickHandler(e)
